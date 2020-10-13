undefined8 main(int param_1,long param_2)
{
  char local_438 [1024];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined2 local_14;

  local_38 = 0x72726142;
  local_34 = 0x73614265;
  local_30 = 0x756f7920;
  local_2c = 0x6e616320;
  local_28 = 0x65766f20;
  local_24 = 0x6c696b72;
  local_20 = 0x6874206c;
  local_1c = 0x6f207369;
  local_18 = 0x3a20656e;
  local_14 = 0x29;
  memset(local_438,0,0x400);
  if (1 < param_1) {
    strncpy(local_438,*(char **)(param_2 + 8),0x3ff);
    printf("Your buffer is ");
    printf(local_438);
  }
  putchar(10);
  return 0;
}
