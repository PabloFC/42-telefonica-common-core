// #include "get_next_line.h"
// #include <fcntl.h>


// int main()
// {
//     int fd;
//     char *line;

//     // Abrimos un archivo para leer (reemplaza "test.txt" con tu archivo de prueba)
//     fd = open("text2.txt", O_RDONLY);
//     if (fd < 0)
//     {
//         perror("Error opening file");
//         return 1;
//     }

//     // Leemos el archivo línea por línea
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line); // Imprimimos la línea leída
//         free(line); // Liberamos la memoria de la línea
//     }

//     // Cerramos el archivo
//     close(fd);

//     return 0;
// }