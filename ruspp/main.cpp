//#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>

int main(void)
{
    GLFWwindow* window;
    // Initialize GLFW
    if (!glfwInit()) {
        return 1;
    }
    // Create window
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return 1;
    }
    glfwMakeContextCurrent(window); // Create Context
    while (!glfwWindowShouldClose(window)) // Main loop
    {
        float scale = 0.2f;
        glClear(GL_COLOR_BUFFER_BIT); // Clear buffer (GL_COLOR_BUFFER_BIT - clear color)

        glBegin(GL_LINES);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(-1, 0);
        glVertex2f(1, 0);
        glVertex2f(0, 1);
        glVertex2f(0, -1);
        glEnd();
        
        glBegin(GL_POINTS);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (float x = -5; x <= 5; x+=0.001f)
        {
            float y = 0.2f/x;
            glVertex2f(x* scale, y* scale);
        }
        glEnd();

        glBegin(GL_POINTS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(0 * scale, 1 * scale);
        glVertex2f(0 * scale, -1 * scale);
        glVertex2f(1* scale, 0* scale);
        glVertex2f(-1* scale, 0* scale);
        glEnd();

        glfwSwapBuffers(window); // Swap previous and buffers
        glfwPollEvents(); // Processing system and other events
    }
    glfwTerminate();
    return 0;
}