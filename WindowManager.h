#pragma once

#include "GLFW/glfw3.h"

namespace SimpleEdit {
	
	class WindowManager
	{
	public:
		WindowManager();
		~WindowManager();
		bool initializeWindow(int, int, const char*);
		void shutdown();
		bool shouldClose() const;
		void pollEvents() const;
		void swapBuffers() const;

	private:
		GLFWwindow* window = nullptr;
		void configureGLFWCallbacks();
	};

}