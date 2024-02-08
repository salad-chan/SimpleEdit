#pragma once

#include "glad/glad.h"
#include "WindowManager.h"
#include <iostream>

namespace SimpleEdit {

	WindowManager::WindowManager() { }

	WindowManager::~WindowManager() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void WindowManager::configureGLFWCallbacks() {
		glfwSetErrorCallback([](int error, const char* description) {
			std::cerr << "GLFW Error (" << error << "): " << description << std::endl;
		});

		//other callbacks if necessary 
	}

	bool WindowManager::initializeWindow(int width, int height, const char* windowName) {
		configureGLFWCallbacks();
		if (!glfwInit()) {
			std::cerr << "Failed to initialize GLFW." << std::endl;
			return false;
		}

		WindowManager::window = glfwCreateWindow(width, height, windowName, nullptr, nullptr);

		if (window == nullptr) {
			std::cerr << "Failed to create GLFW window." << std::endl;
			glfwTerminate();
			return false;
		}

		glfwMakeContextCurrent(window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cerr << "Failed to initialize GLAD." << std::endl;
			glfwDestroyWindow(window);
			glfwTerminate();
			return false;
		}

		return true;
	}
}