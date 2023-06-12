# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <locale.h>

int main() {
	setlocale(LC_ALL,"portuguese");
	
    char usuario[6], str[6]="grama";
    int i, k, tentativa=6, tamanho, comparador_str_usuario, contador_cinza=0;
    
    printf("\tTermo.UFF > Palavra de 5 Caracteres lowercase");
    
    while (tentativa != 0)
    {
    	// Formatação da entrada do usuário - Deve ser uma palavra de 5 caracteres
        do
        {
	        printf("\nDigite seu palpite > ");
	        scanf(" %s", &usuario);
	        tamanho = strlen(usuario);
        } while (tamanho != 5);
        
		comparador_str_usuario = strcmp(usuario, str);
		
		if (comparador_str_usuario == 0)
        	{
        		printf("\nParabéns! Você acertou a palavra > %s", str);
        		return 0;
			}
        
        for (i=0; str[i] != '\0'; i++)
        {
			// Verde
            if (usuario[i] == str[i])
            {
                printf("\n%c = Verde! na posiçao %d", usuario[i], i + 1);
            }
            // Amarelo & Cinza
            else
            {
            	for (k = 0; str[k] != '\0'; k++)
            	{	
            		// Amarelo
            		if (usuario[i] == str[k])
            		{
            			printf("\n%c = Amarelo!", usuario[i]);
            			contador_cinza = 0;
            			break;
					}
					else
					{
						contador_cinza++;
					}
					
					// Cinza
					if (contador_cinza == 5)
					{
						printf("\n%c = Cinza! na posição %d", usuario[i], i + 1);
						contador_cinza = 0;
					}
					if ((k == 4) && (contador_cinza != 0))
					{
						contador_cinza = 0;
					}
					
					
				}
			}
        }
        
      	tentativa--;
    }
    
    printf("\nQue pena, não foi dessa vez.\nA palavra era > %s", str);
    
	return 0;
}
