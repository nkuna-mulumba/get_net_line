/*
#include "get_next_line.h"

int main()
{
    char *test_str = strdup("Hello\nWorld\nThis\nIs\nA\nTest\n");
    char *remainder = test_str;
    char *line;
    
    while ((line = ft_extract_line(&remainder)) != NULL)
    {
        printf("Extracted line: %s", line);
        free(line);
    }
    return 0;
}

Strings com várias linhas.
Hello\nWorld\nThis\nIs\nA\nTest\n



Strings sem novas linhas.
Adicione tratamento de erros robusto para lidar com entradas



Strings vazias.



Testar com Arquivos: 
Teste a função com conteúdo de arquivos para garantir 
que ela funcione corretamente na leitura de arquivos 
linha por linha.
*/