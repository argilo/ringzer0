import java.security.SecureRandom;

public class KeyGen
{
    public static void main(String[] args) {
        for (int i = 0; i < 1000000; i++) {
            System.out.println(bytesToHex(generateKey().getBytes()));
        }
    }

    private static String bytesToHex(final byte[] bytes) {
        final char[] hexArray = "0123456789abcdef".toCharArray();
        final char[] hexChars = new char[bytes.length * 2];
        for (int j = 0; j < bytes.length; ++j) {
            final int v = bytes[j] & 0xFF;
            hexChars[j * 2] = hexArray[v >>> 4];
            hexChars[j * 2 + 1] = hexArray[v & 0xF];
        }
        return new String(hexChars);
    }

    public static String generateKey() {
        final SecureRandom sr = new SecureRandom();
        final byte[] key = new byte[8];
        sr.nextBytes(key);
        return new String(key);
    }
}
