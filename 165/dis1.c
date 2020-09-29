undefined8 main(int param_1,long param_2)
{
  char local_408 [1024];

  if (1 < param_1) {
    strcpy(local_408,*(char **)(param_2 + 8));
    printf("Your buffer is %s\n",local_408);
  }
  return 0;
}
