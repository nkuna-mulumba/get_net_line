#include "get_next_line.h"

int main() {
    int fd = open("test.txt", O_RDONLY); // Abre o arquivo de teste para leitura
    int fd2 = open("testcuatro.txt", O_RDONLY);
    int fd3 = open("quijote.txt", O_RDONLY);
    if (fd == -1) {
        perror("Erro ao abrir o arquivo");
        return EXIT_FAILURE;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line); // Exibe a linha lida
        free(line); // Libera a memória da linha
    }

    close(fd); // Fecha do primeiro arquivo como (3)
    close(fd2); //Fecha do segundo arquivo como (4)
    close(fd3); //Fecha do segundo arquivo como (5)
    return EXIT_SUCCESS;
}
