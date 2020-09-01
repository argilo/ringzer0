
uchar * Decrypt(void *key_in,uchar *ciphertext,size_t length)

{
  DES_key_schedule schedule;
  uchar iv [8];
  int num;

  num = 0;
  Res.4253 = (uchar *)malloc(length);
  memcpy(iv,key_in,8);
  DES_set_odd_parity((DES_cblock *)iv);
  DES_set_key_checked((const_DES_cblock *)iv,&schedule);
  DES_cfb64_encrypt(ciphertext,Res.4253,length,&schedule,(DES_cblock *)iv,&num,0);
  return Res.4253;
}
