//#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>

int main(void)
{
    GLFWwindow* window;
    if (!glfwInit()) {
        return 1;
    }
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return 1;
    }
    // Set scale here
    float scale = 0.2f;
    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

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
            // Set function here
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

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}