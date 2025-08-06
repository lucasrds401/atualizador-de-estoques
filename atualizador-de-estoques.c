#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void traco(int num){
	int i;
	for(i = 0; i < num; i++){
		printf("-");
	}
	printf("\n");
} // Função que gera traços para deixar a execução mais organizada e bonita.

typedef struct {
	
	char nome[100], codigo[7];
	int estoque;
	float preco;
	
}produtos; // Lista de tipos de atributos para cada produto.

void formulario (produtos *mercado, int inicio, int limite); //alocação dinámica

int main(){
	setlocale(LC_ALL, "portuguese");
	int i, qntd, op;

	printf("Digite quantos produtos você quer cadastrar: ");
	scanf("%d", &qntd); 

	produtos *mercado = (produtos *) malloc (qntd * sizeof(produtos));
	
	formulario(mercado, 0, qntd);
	
    traco(60);
    printf("             MENU DE OPÇÕES             \n");
    traco(60);
    
    printf("[1] Listar todos os produtos \n[2] Adicionar novos produtos \n[3] Sair\n");
    traco(60);
    printf("Digite uma opção: ");
    scanf("%d", &op);
    traco(60);
    
    for(i = 0; op > 3 || op == 0; i++){
    	printf("Opção inválida! Digite um número de acordo com o menu: ");
    	scanf("%d", &op);
		}
		
	if(op == 1){
		for(i = 0; i < qntd; i++){
		printf("%dº produto: \n", i+1);
		printf("Nome: %s\n", mercado[i].nome);
		printf("Código: %s\n", mercado[i].codigo);
		printf("Quantidade em Estoque: %d\n", mercado[i].estoque);
		printf("Preço: %.2f\n", mercado[i].preco);
		traco(60);
	}
}

	if(op == 2){
	int qntd_nv, ins;
    
	printf("Digite a quantidade de produtos que você quer inserir: ");
    scanf("%d", &ins);
    qntd_nv = qntd + ins;
	mercado = realloc(mercado, qntd_nv * sizeof(produtos));
	
	formulario(mercado, qntd, qntd_nv);
}
	return 0;
}
void formulario( produtos *mercado, int inicio, int limite){
	int i;
	while (getchar() != '\n'); 
		for(i = inicio; i < limite; i++){
		traco(60);
		printf("%dº Produto: \n\n", i + 1);
		
		printf("Nome: ");
		fgets(mercado[i].nome, 100, stdin);
		mercado[i].nome[strcspn(mercado[i].nome, "\n")] = '\0';

		traco(60);
		printf("Código: ");
		scanf("%6s", mercado[i].codigo);

		traco(60);
		printf("Quantidade no estoque: ");
		scanf("%d", &mercado[i].estoque);

		traco(60);
		printf("Preço: ");
		scanf("%f", &mercado[i].preco);

		while (getchar() != '\n'); 
}
}
