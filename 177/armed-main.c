
/* WARNING: Could not reconcile some variable overlaps */

undefined4 main(int argc,int argv)

{
  bool bVar1;
  void *__dest;
  int iVar2;
  void *__src;
  undefined4 local_54;
  undefined4 uStack80;
  undefined4 uStack76;
  undefined4 uStack72;
  undefined4 local_44;
  undefined4 uStack64;
  undefined4 uStack60;
  undefined4 uStack56;
  undefined4 local_34;
  undefined2 local_30;
  undefined local_2e;
  uint key_first;
  uint key_second;
  undefined local_24;
  void *plaintext;
  void *ciphertext;
  int local_18;
  int local_14;

  key_first = 0x73734070;
  key_second = 0x64723057;
  local_24 = 0;
  local_54 = 0x727fcc57;
  uStack80 = 0x7d511d48;
  uStack76 = 0x998151e7;
  uStack72 = 0xcaa1571e;
  local_44 = 0x93505e9;
  uStack64 = 0xf86545f9;
  uStack60 = 0x6cdedebe;
  uStack56 = 0x48d78c3d;
  local_34 = 0xe2c85744;
  local_30 = 0xe715;
  local_2e = 0;
  if (argc < 0xb) {
    if (argc < 0xd) {
      *(undefined *)((int)&key_first + argc) =
           *(undefined *)(*(int *)(argv + (argc / 2 + -2) * 4) + 1);
    }
    else {
      *(undefined *)((int)&key_first + argc) =
           *(undefined *)(*(int *)(argv + (argc / 2 + 1) * 4) + 1);
    }
  }
  else {
    *(undefined *)((int)&key_first + argc) = **(undefined **)(argv + (argc / 2 + -1) * 4);
  }
  if (**(char **)(argv + 8) == 'A') {
    key_first._0_3_ = CONCAT12(**(undefined **)(argv + 8),(ushort)key_first);
    key_first = key_first & 0xff000000 | (uint)(uint3)key_first;
  }
  else {
    key_first = key_first & 0xffffff | (uint)**(byte **)(argv + 0xc) << 0x18;
  }
  local_14 = atoi(*(char **)(argv + 4));
  while (bVar1 = local_14 < 9, local_14 = local_14 + 1, bVar1) {
    **(char **)(argv + local_14 * 4) = **(char **)(argv + local_14 * 4) + '\x02';
  }
  if (local_14 < 1) {
    key_first._0_2_ = CONCAT11(1,(undefined)key_first);
    key_first = key_first & 0xffff0000 | (uint)(ushort)key_first;
  }
  else {
    key_first._0_2_ = CONCAT11(2,(undefined)key_first);
    key_first = key_first & 0xffff0000 | (uint)(ushort)key_first;
  }
  key_first = key_first & 0xffffff;
  if ((uint)**(byte **)(argv + 0xc) + (uint)**(byte **)(argv + 0x10) +
      (uint)**(byte **)(argv + 0x14) == 0xec) {
    key_second = key_second & 0xffffff00 | (uint)**(byte **)(argv + 0x10);
  }
  if (**(char **)(argv + 0x14) == '3') {
    key_second = key_second & 0xffffff | (uint)**(byte **)(argv + 0x1c) << 0x18;
  }
  else {
    key_second._0_2_ = CONCAT11(**(undefined **)(argv + 0xc),(undefined)key_second);
    key_second = key_second & 0xffff0000 | (uint)(ushort)key_second;
  }
  if (argc == 0xf) {
    key_first._0_3_ = CONCAT12(0x15,(ushort)key_first);
    key_first = (uint)(uint3)key_first;
  }
  key_first = key_first | (uint)**(byte **)(argv + 0xc) << 0x18;
  iVar2 = atoi(*(char **)(argv + 0x24));
  if (iVar2 == 0xd558) {
    iVar2 = atoi(*(char **)(argv + 0x24));
    key_second._0_3_ = CONCAT12((char)iVar2,(ushort)key_second);
    key_second = key_second & 0xff000000 | (uint)(uint3)key_second;
  }
  else {
    iVar2 = atoi(*(char **)(argv + 0x24));
    if (iVar2 == 0x873e) {
      key_second._0_3_ = CONCAT12(0x3e,(ushort)key_second);
      key_second = key_second & 0xff000000 | (uint)(uint3)key_second;
    }
  }
  key_first = key_first & 0xffffff00 | (uint)(byte)~(**(byte **)(argv + 0x28) ^ 0x21);
  local_18 = 0;
  while (local_18 < 8) {
    local_18 = local_18 + 1;
  }
  ciphertext = malloc(0x27);
  plaintext = malloc(0x27);
  memcpy(ciphertext,&local_54,0x27);
  __dest = plaintext;
  __src = (void *)Decrypt(&key_first,ciphertext,0x27);
  memcpy(__dest,__src,0x27);
  printf("Decrypted text\t : %s \n",plaintext);
  return 0;
}
