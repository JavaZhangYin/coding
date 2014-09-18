//package token.exe;

import java.io.ByteArrayOutputStream;
import java.io.UnsupportedEncodingException;
import java.security.MessageDigest;

public class TencentWeiboEncryption {

    private static final String HEXSTRING = "0123456789ABCDEF";


    /**
     * 获取指定字符串的md5值
     * @param originalText
     * @return
     * @throws Exception
     */
    private static String md5(String originalText) throws Exception {
        
        byte buf[] = originalText.getBytes("ISO-8859-1");
        StringBuffer hexString = new StringBuffer();
        String result = "";
        String digit = "";
        try {
            MessageDigest algorithm = MessageDigest.getInstance("MD5");
            algorithm.reset();
            algorithm.update(buf);
            byte[] digest = algorithm.digest();
            for (int i = 0; i < digest.length; i++) {
                digit = Integer.toHexString(0xFF & digest[i]);
                if (digit.length() == 1) {
                    digit = "0" + digit;
                }
                hexString.append(digit);
            }
            result = hexString.toString();
        } catch (Exception ex) {
            result = "";
        }
        return result.toUpperCase();
    }


    /**
     * 将16进制编码转换为相应的ASCII字符串
     * @param md5str
     * @return
     * @throws UnsupportedEncodingException
     */
    private static String hexchar2bin(String md5str) throws UnsupportedEncodingException {
        
        ByteArrayOutputStream baos = new ByteArrayOutputStream(md5str.length() / 2);
        for (int i = 0; i < md5str.length(); i = i + 2) {
            baos.write((HEXSTRING.indexOf(md5str.charAt(i)) << 4 | HEXSTRING.indexOf(md5str.charAt(i + 1))));
        }
        return new String(baos.toByteArray(), "ISO-8859-1");
    }

   
    /**
     * 获取加密后的密码
     * @param qq
     * @param password
     * @param verifycode
     * @return
     * @throws Exception
     */
    public static String getPassword(String qq, String password, String verifycode) throws Exception {
        String P = hexchar2bin(md5(password));
        String U = md5(P + hexchar2bin(qq.replace("\\x", "").toUpperCase()));
        String V = md5(U + verifycode.toUpperCase());
        return V;
    }
}
