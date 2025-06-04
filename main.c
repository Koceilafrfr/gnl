/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:26:06 by yzidani           #+#    #+#             */
/*   Updated: 2025/06/04 19:33:11 by yzidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

void test_file(char *filename) {
    printf("=== Testing: %s ===\n", filename);
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("open");
        return;
    }

    char *line;
    int i = 1;
    while ((line = get_next_line(fd)) != NULL) {
        printf("Line %d: %s", i++, line);
        free(line);
    }
    printf("Line %d: %s\n", i, "NULL");
    close(fd);
    printf("=====================\n\n");
}

int main(void) {
    get_next_line(-1);
    // test_file("test/error.txt");
    // test_file("test/one_line_no_nl.txt");
    // test_file("test/one_line_with_nl.txt");
    // test_file("test/multiple_lines.txt");
    // test_file("test/only_newlines.txt");
    // test_file("test/very_long_line.txt");
    return 0;
} 
