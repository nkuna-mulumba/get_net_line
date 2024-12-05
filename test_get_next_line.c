#include "get_next_line.h"

int main() {
    int fd = open("test.txt", O_RDONLY); // Abre o arquivo de teste para leitura
    if (fd == -1) {
        perror("Erro ao abrir o arquivo");
        return EXIT_FAILURE;
    }

    char	*line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line); // Exibe a linha lida
        free(line); // Libera a memória da linha
    }

    close(fd); // Fecha o arquivo
    return EXIT_SUCCESS;
}
