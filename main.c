#include <stdio.h>
#include <stdlib.h>

void entradaVisitante()
{
	FILE *arquive;
	arquive = fopen("controle.bin","wb");
	char nome[100];
	printf("Digite o nome do visitante que esta dando entrada: ");
	scanf("%s",nome);
	fwrite(&nome[0], sizeof(char), 100, arquive);
	fclose(arquive);
}

void saidaVisitante()
{

}

void listaVisitante()
{
	FILE *arquive;
	char nome[100];
	arquive = fopen("controle.bin","rb");
	fread(&nome[0], sizeof(char), 100, arquive);
	printf("%s\n\n\n",nome);
}

int main(int argc, char *argv[]) 
{
	int itemMenu;
	itemMenu = 1;
	do 
	{
	    printf("1. Entrada de visitante.\n\n");
	    printf("2. Saida de visitante.\n\n");
	    printf("3. Lista de visitantes presentes.\n\n");
        printf("0. Sair\n\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &itemMenu);

		switch (itemMenu)
		{
            case 0:
				return 0;
            break;

			case 1:
				entradaVisitante();
            break;

			case 2:
				saidaVisitante();
            break;

			case 3:
				listaVisitante();
			break;
			
			default:
				printf("Opcao invalida!!\n\n");
		}
		
	}while(itemMenu!=0);
	system("pause");
	return 0;
}
