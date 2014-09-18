// package token.def;

import java.io.Serializable;
import java.util.Properties;

public class TLoginParams implements Serializable {
    
    private static final long serialVersionUID = 6120319409538285515L;
    private String saltUin;
    private String dataRedirect;
    private String loginSig;
    private String loginUrl;
    private String imgURl;
    private String imgCookie;
    private boolean isLogin = true;
    private Properties prop;
    
    public String getSaltUin() {
        return saltUin;
    }
    public void setSaltUin(String saltUin) {
        this.saltUin = saltUin;
    }
    public String getDataRedirect() {
        return dataRedirect;
    }
    public void setDataRedirect(String dataRedirect) {
        this.dataRedirect = dataRedirect;
    }
    public String getLoginSig() {
        return loginSig;
    }
    public void setLoginSig(String loginSig) {
        this.loginSig = loginSig;
    }
    public String getLoginUrl() {
        return loginUrl;
    }
    public void setLoginUrl(String loginUrl) {
        this.loginUrl = loginUrl;
    }
    public String getImgURl() {
        return imgURl;
    }
    public void setImgURl(String imgURl) {
        this.imgURl = imgURl;
    }
    public String getImgCookie() {
        return imgCookie;
    }
    public void setImgCookie(String imgCookie) {
        this.imgCookie = imgCookie;
    }
    public boolean isLogin() {
        return isLogin;
    }
    public void setLogin(boolean isLogin) {
        this.isLogin = isLogin;
    }
    public Properties getProp() {
        return prop;
    }
    public void setProp(Properties prop) {
        this.prop = prop;
    }
    
    @Override
    public String toString() {
        return "TLoginParams [saltUin=" + saltUin + ", dataRedirect="
                + dataRedirect + ", loginSig=" + loginSig + ", loginUrl="
                + loginUrl + ", imgURl=" + imgURl + ", imgCookie=" + imgCookie
	    + ", isLogin=" + isLogin + ", prop=" + prop + "]";
    }    
}
