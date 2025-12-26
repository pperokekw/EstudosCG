#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main() {
	glfwInit(); // Inicializando o glfw (obvio)
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3); // Falando pro glfw qual versao do opengl estamos usando
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // mesma coisa pra "versao" minor 
	// isto é, estamos dizendo pro glfw que vamos utilizar a versao 3.3 do opengl (3 - major e .3 - minor);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Setando as funções do opengl para o glfw 


	GLFWwindow* window = glfwCreateWindow(800,600,"Estudamno OPENGL",NULL,NULL); // criando a janela (800x800) com  nome "Estudamno OPENGL

	if (window == NULL) {
		std::cout << "Falha ao criar a janela, encerrando" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window); // falando pro glfw que queremos USAR a janela que criamos

	gladLoadGL(); 

	glViewport(0, 0, 800, 600);/* os dois primeiros parametros setam a localização do canto inferior esquerdo (0,0)

	até onde todos os pixels devem ser renderizados no canto superior direito -(800,600)*/
	glClearColor(0.27f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);


	bool temp = false;

	while (!glfwWindowShouldClose(window)) {

		double tempo = glfwGetTime(); // pegando tempo que passou desde que começou o programa 
		if ((int)ceil(tempo) % 2 == 1) { // condicional para trocar de cor (se for um segundo par)
			temp = true;
		}
		else {
			temp = false;
		}

		if (temp) { // se for um segundo par a gnt troca de cor, alterando o azul, peguei so a parte fracionada
			glClearColor(1.0f, 0.48f, tempo-(long)tempo, 1.0f); // tempo - parte inteira de tempo. Ex: 3.14159 - 3 => .14159
			glClear(GL_COLOR_BUFFER_BIT);
			glfwSwapBuffers(window);

		}

		glfwPollEvents(); // checa se houve algum evento na janela!!!


		std::cout << tempo << std::endl;
	}


	glfwDestroyWindow(window); // fechano a janela antes de fechar tudao
	glfwTerminate(); // Fecha o glfw (obovio^2)
	return 0;
}