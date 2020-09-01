#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/des.h>

int main(void) {
  DES_key_schedule schedule;
  DES_cblock iv;
  int num;

  unsigned char ciphertext[] = {
    0x57, 0xcc, 0x7f, 0x72, 0x48, 0x1d, 0x51, 0x7d,
    0xe7, 0x51, 0x81, 0x99, 0x1e, 0x57, 0xa1, 0xca,
    0xe9, 0x05, 0x35, 0x09, 0xf9, 0x45, 0x65, 0xf8,
    0xbe, 0xde, 0xde, 0x6c, 0x3d, 0x8c, 0xd7, 0x48,
    0x44, 0x57, 0xc8, 0xe2, 0x15, 0xe7, 0x00, 0x00
  };
  unsigned char plaintext[40] = {0};
  unsigned char key[] = {
    0x70, 0x40, 0x73, 0x73, 0x57, 0x30, 0x72, 0x64
  }; // "p@ssW0rd"

  key[1] = 0x02;

  key[2] = 0x41;
  //key[2] = 0x15;

  key[6] = 0x58;
  //key[6] = 0x3e;

  for (int k0 = 0; k0 < 0x80; k0 += 2) {
    key[0] = k0 ^ 0xde;

    for (int k3 = 0; k3 < 0x80; k3 += 2) {
      key[3] = k3;
      key[5] = k3;

      for (int k4 = 0; k4 < 0x80; k4 += 2) {
        key[4] = k4;

        num = 0;
        memcpy(iv, key, 8);
        DES_set_odd_parity(&iv);
        DES_set_key_checked(&iv, &schedule);
        DES_cfb64_encrypt(ciphertext, plaintext, 39, &schedule, &iv, &num, 0);

        int good = 1;
        for (int i = 0; i < 32; i++) {
          if (plaintext[i] >= 0x80) {
            good = 0;
            break;
          }
        }

        if (good) {
          printf("arg3=%c arg4=%c arg10=%c\n", k3, k4, k0);
          for (int i = 0; i < 40; i++) {
            printf("%c", plaintext[i]);
          }
          printf("\n\n");
        }
      }
    }
  }

  return 0;
}
