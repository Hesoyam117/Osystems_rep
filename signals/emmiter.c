// Программа, которая отправляет другому процессу сигнал SIGUSR1 или SIGUSR2. 
// Процесс, которому нужно отправить сигнал выбирается по его идентификатору.
// Для запуска программы необходимо ввести в консоль ./emitter <PID> <SIGNAL>
// Где PID - идентификатор процесса, а SIGNAL - пользовательский сигнал SIGUSR1 или SIGUSR2
// Если что-то пошло не так попробовать заново скомпилировать командой gcc emitter.c -o emitter и повторить первую инструкцию

#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if (argc == 3)
  {
    if ((strcmp(argv[2], "SIGUSR1") == 0) || (strcmp(argv[2], "SIGUSR2") == 0))
    {
      // getting pid
      int pid = atoi(argv[1]);
      int sig;
      // trying to define signal number, int
      if ((strcmp(argv[2], "SIGUSR1") == 0))
      {
        sig = 10;
      }
      else
      {
        sig = 12;
      }
      // send signal
      kill(pid, sig);
      printf("Signal sended.\n");
    }
    // raise error
    else
    {
      printf("Argumets error.\n");
    }
  }
  else if (argc > 3)
  {
    printf("Too many arguments supplied.\n");
  }
  else
  {
    printf("Argumets error.\n");
  }
}