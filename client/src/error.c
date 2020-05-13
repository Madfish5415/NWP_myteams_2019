/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** error.c
*/

#include <stdio.h>
#include <string.h>
#define PROJECT_ARGUMENTS_SIZE (3)

int catch_error(int ac, char **av)
{
  if (ac != PROJECT_ARGUMENTS_SIZE) {
    return 84;
  }
  for (unsigned long i = 0; i < strlen(av[2]); i++) {
    if (av[2][i] < '0' || av[2][i] > '9') {
      fprintf(stderr, "Invalid port argument.\n");
      return 84;
    }
  }
  return 0;
}