#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<String>
#include<assert.h>//断言
#include <iostream>

void processInput(GLFWwindow* window)//处理输入
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(1200, 800, "opengl_window", NULL, NULL);//创建窗口

    // 1. 检查窗口是否创建成功
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // 2. 关键：初始化 GLAD（你缺的就是这一步）
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //设置清空屏幕所用的颜色，表状态，会一直存在//f是浮点数，0.2，0.3，0.3，1.0代表颜色的rgba值，范围0-1，1表示不透明，0表示透明

    //3.循环
	while (!glfwWindowShouldClose(window)) // 渲染循环
    {
        processInput(window);//处理输入

        //渲染部分。
        
        glClear(GL_COLOR_BUFFER_BIT); //清空颜色缓冲
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;//退出程序，并在终端输出0，表示程序正常退出，也可以写成1，人能看懂就行
}