// package token.exe;

import java.io.ByteArrayInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.UnsupportedEncodingException;
import java.net.URLEncoder;
import java.security.KeyManagementException;
import java.security.NoSuchAlgorithmException;
import java.security.cert.CertificateException;
import java.security.cert.X509Certificate;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Properties;
import java.util.Scanner;

import javax.net.ssl.SSLContext;
import javax.net.ssl.TrustManager;
import javax.net.ssl.X509TrustManager;

import org.apache.http.Header;
import org.apache.http.HttpHeaders;
import org.apache.http.HttpHost;
import org.apache.http.HttpResponse;
import org.apache.http.HttpVersion;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.params.CookiePolicy;
import org.apache.http.client.params.HttpClientParams;
import org.apache.http.conn.params.ConnRoutePNames;
import org.apache.http.conn.routing.HttpRoute;
import org.apache.http.conn.scheme.PlainSocketFactory;
import org.apache.http.conn.scheme.Scheme;
import org.apache.http.conn.scheme.SchemeRegistry;
import org.apache.http.conn.ssl.SSLSocketFactory;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.impl.conn.tsccm.ThreadSafeClientConnManager;
import org.apache.http.message.BasicHeader;
import org.apache.http.params.CoreConnectionPNames;
import org.apache.http.params.HttpParams;
import org.apache.http.params.HttpProtocolParams;
import org.apache.http.params.SyncBasicHttpParams;
import org.apache.http.util.EntityUtils;
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;

import token.TencentWeiboOAuth;
import token.def.TLoginParams;

import com.tencent.weibo.beans.RouteCfg;

public class TencentWeiboLoginer {
    
    private DefaultHttpClient httpClient;
    
    //默认连接配置参数
    private static final int CONNECT_TIME_OUT = 5000;
    private static final int SOCKET_TIME_OUT = 5000;
    private static final int MAX_CONNECTIONS_PRE_HOST = 20;
    private static final int MAX_TOTAL_CONNECTIONS = 200;
    
    public TencentWeiboLoginer() {
        this(CONNECT_TIME_OUT, SOCKET_TIME_OUT, MAX_CONNECTIONS_PRE_HOST, MAX_TOTAL_CONNECTIONS, null, null);
    }
    
    public TencentWeiboLoginer(int connectTimeOut, int socketTimeOut, int maxConnectionsPreHost,
			       int maxTotalConnections, List<RouteCfg> routeCfgs, HttpHost proxy) {
                
        //注册ssl协议
        SSLContext ssl = null;
        SchemeRegistry schemeRegistry = null;
        X509TrustManager x509TrustManager = null;
        SSLSocketFactory sslSocketFactory = null;
        try {
            ssl = SSLContext.getInstance("TLS");
            x509TrustManager = new X509TrustManager() {
                
                @Override
                public X509Certificate[] getAcceptedIssuers() {
                    // TODO Auto-generated method stub
                    return null;
                }
                
                @Override
                public void checkServerTrusted(X509Certificate[] chain, String authType)
		    throws CertificateException {
                    // TODO Auto-generated method stub
                    
                }
                
                @Override
                public void checkClientTrusted(X509Certificate[] chain, String authType)
		    throws CertificateException {
                    // TODO Auto-generated method stub
                    
                }
		};
            ssl.init(null, new TrustManager[]{x509TrustManager}, null);
            sslSocketFactory = new SSLSocketFactory(ssl);            
            sslSocketFactory.setHostnameVerifier(SSLSocketFactory.ALLOW_ALL_HOSTNAME_VERIFIER);
            
            //注册http和https协议
            schemeRegistry = new SchemeRegistry();
            schemeRegistry.register(new Scheme("https", 443, sslSocketFactory));
	    //            schemeRegistry.register(new Scheme("http", 80, PlainSocketFactory.getSocketFactory()));
        } catch (NoSuchAlgorithmException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (KeyManagementException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        
        //配置客户端链接管理类
        ThreadSafeClientConnManager connManager = new ThreadSafeClientConnManager(schemeRegistry);
        connManager.setDefaultMaxPerRoute(maxConnectionsPreHost);
        connManager.setMaxTotal(maxTotalConnections);
        
        //配置http请求连接参数
        HttpParams httpParams = new SyncBasicHttpParams();
        httpParams.setParameter(CoreConnectionPNames.CONNECTION_TIMEOUT, connectTimeOut);
        httpParams.setParameter(CoreConnectionPNames.SO_TIMEOUT, socketTimeOut);
        
        //http协议参数配置
        HttpProtocolParams.setVersion(httpParams, HttpVersion.HTTP_1_1);
        HttpProtocolParams.setUseExpectContinue(httpParams, false);
        
        //启用cookie
        HttpClientParams.setCookiePolicy(httpParams, CookiePolicy.BROWSER_COMPATIBILITY);
        
        //对特定ip端口修改最大连接数
        if (routeCfgs != null) {
            for (RouteCfg routeCfg : routeCfgs) {
                HttpHost host = new HttpHost(routeCfg.getHost(), routeCfg.getPort());
                connManager.setMaxForRoute(new HttpRoute(host), routeCfg.getMaxConnetions());
            }
        }
        
        //初始化httpClient
        httpClient = new DefaultHttpClient(connManager,httpParams);
        
        //添加headers
        List<Header> headers = new ArrayList<Header>();
        headers.add(new BasicHeader(HttpHeaders.ACCEPT, "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8"));
        headers.add(new BasicHeader(HttpHeaders.ACCEPT_LANGUAGE, "zh-cn,zh;q=0.8,en-us;q=0.5,en;q=0.3"));
        headers.add(new BasicHeader(HttpHeaders.ACCEPT_CHARSET, "UTF-8"));
        headers.add(new BasicHeader(HttpHeaders.USER_AGENT, "Mozilla/5.0 (Windows NT 5.1; rv:25.0) Gecko/20100101 Firefox/25.0"));
        headers.add(new BasicHeader(HttpHeaders.CONNECTION, "keep-alive"));
        headers.add(new BasicHeader("X-Forwarded-For", "192.168.0.1"));
        headers.add(new BasicHeader("Client-IP", "192.168.0.1"));
        headers.add(new BasicHeader("API-RemoteIP", "192.168.0.1"));
        httpClient.getParams().setParameter("http.default-headers", headers);
        
        //设置代理
        if (proxy != null) {
            httpClient.getParams().setParameter(ConnRoutePNames.DEFAULT_PROXY, proxy);
        }
                
    }
    
    /**
     * 模拟腾讯微博登陆
     * @return code值
     */
    public TLoginParams doLogin(String username, String password) {
        
        Properties properties = initProperties();
        String clientID = properties.getProperty("client_id");
        String redirectURI = properties.getProperty("redirect_uri");
        
        HashMap<String, String> urlMap = getUrlMap(clientID, redirectURI);
        String dataRedirect = urlMap.get("data-redirect");
        
        HashMap<String, String> loginInfoMap = preLogin(urlMap);
        String loginSig = loginInfoMap.get("login_sig");
        String loginUrl = loginInfoMap.get("login_url");
        
        HashMap<String, String> checkMap = isHasVC(dataRedirect, username, loginSig, loginUrl);
        String isHasVC = checkMap.get("isHasVC");
        String vc = checkMap.get("vc");
        String saltUin = checkMap.get("saltUin");
        
        TLoginParams tLoginParams = new TLoginParams();
        if (Integer.parseInt(isHasVC) != 0) {
            tLoginParams.setDataRedirect(dataRedirect);
            tLoginParams.setLoginSig(loginSig);
            tLoginParams.setLoginUrl(loginUrl);
            tLoginParams.setSaltUin(saltUin);
            tLoginParams.setImgURl(getVCode(username));
            return tLoginParams;
        }
        
        String checkSigUrl = finalLogin(vc, saltUin, dataRedirect, username, 
					password, loginSig, loginUrl);
        Properties result = authorize(loginUrl, checkSigUrl);
        tLoginParams.setProp(result);
        return tLoginParams;
    }
    
    /**
     * 有验证码时验证登陆
     * @param vc
     * @param saltUin
     * @param dataRedirect
     * @param username
     * @param password
     * @param loginSig
     * @param loginUrl
     * @return
     */
    public TLoginParams doLoginByVC(String vc, String saltUin, String dataRedirect, String username, 
				    String password, String loginSig, String loginUrl) {
        
        TLoginParams tLoginParams = new TLoginParams();
        
        String checkSigUrl = finalLogin(vc, saltUin, dataRedirect, username, password, loginSig, loginUrl);
        if (checkSigUrl.equals("您输入的验证码不正确，请重新输入。")) {
            tLoginParams.setLogin(false);
            return tLoginParams;
        }
        Properties prop = authorize(loginUrl, checkSigUrl);
        
        tLoginParams.setProp(prop);
        return tLoginParams;
    }
    
    /**
     * 初始化登陆,获取含有sessionkey的url提交链接
     * @param clientID 应用ID
     * @param redirectURI 应用回调地址
     * @return
     */
    private HashMap<String, String> getUrlMap(String clientID, String redirectURI) {
        
        String url = "https://open.t.qq.com/cgi-bin/oauth2/authorize?" 
                + "client_id=" + clientID
                + "&response_type=code"
                + "&redirect_uri=" + redirectURI
	    + "&forcelogin=true";
        Header[] headers = new BasicHeader[]{
	    new BasicHeader(HttpHeaders.HOST, "open.t.qq.com")
        };

        String htmlDatas = httpGetDatas(url, headers);
        HashMap<String, String> map = new HashMap<String, String>();
        String data_redirect = null;
        String data_proxy = null;
        
        Document  document = Jsoup.parse(htmlDatas);
        Element element = document.getElementsByTag("noscript").first();
        data_redirect = element.attr("data-redirect");
        map.put("data-redirect", data_redirect);
        data_proxy = element.attr("data-proxy");
        map.put("data-proxy", data_proxy);
        return map;
    }
    
    /**
     * 预登陆腾讯微博，获取login_sig
     * @param urlMap 初始化登陆返回的urlMap
     * @return
     */
    private HashMap<String, String> preLogin(HashMap<String, String> urlMap) {
        
        String s_url_encode = null;
        String proxy_url_encode = null;
        String script = null;
        try {
            s_url_encode = URLEncoder.encode(urlMap.get("data-redirect"), "UTF-8");
            proxy_url_encode = URLEncoder.encode(urlMap.get("data-proxy"), "UTF-8");
        } catch (UnsupportedEncodingException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        String url = "https://ui.ptlogin2.qq.com/cgi-bin/login?appid=46000101"
                + "&s_url=" + s_url_encode
                + "&proxy_url=" + proxy_url_encode
                + "&f_url=loginerroralert"
                + "&style=13" 
                + "&daid=6"
                + "&pt_no_auth=1"
                + "&hide_close_icon=1" 
                + "&link_target=blank"
                + "&target=blank"
                + "&hide_title_bar=1"
                + "&no_drop_domain=1"
                + "&dummy=1"
                + "&bgcolor=ffffff"
	    + "&r=" + Math.random();
        Header[] headers = new BasicHeader[]{
	    new BasicHeader(HttpHeaders.HOST, "ui.ptlogin2.qq.com")
        };
        String htmlDatas = httpGetDatas(url, headers);
        
        Document document = Jsoup.parse(htmlDatas);
        Element headElement = document.getElementsByTag("head").first();
        Element element = headElement.getElementsByTag("script").first();
        script = element.html();
        
        String login_sig = script.substring(script.indexOf("login_sig:"), script.indexOf("\",clientip"));
        String login_sig_key = login_sig.substring(login_sig.indexOf("\"") + 1);
        
        HashMap<String, String>    loginMap = new HashMap<String, String>();
        loginMap.put("login_sig", login_sig_key);
        loginMap.put("login_url", url);
        return loginMap;
    }    
    
    /**
     * 检查预登陆时是否需要验证码
     * @param dataRedirect 初始化登陆返回的map
     * @param username 用户名
     * @param loginSig TODO
     * @param loginUrl TODO
     * @return
     */
    private HashMap<String, String> isHasVC(String dataRedirect, String username, 
					    String loginSig, String loginUrl){
        
        String url = null;
        try {
            url = "https://ssl.ptlogin2.qq.com/check?"
                    + "regmaster="
                    + "&uin=" + username
                    + "&appid=46000101"
                    + "&js_ver=10052"
                    + "&js_type=1"
                    + "&login_sig=" + loginSig
		+ "&u1=" + URLEncoder.encode(dataRedirect, "UTF-8")
		+ "&r=" + Math.random();
        } catch (UnsupportedEncodingException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        Header[] headers = new BasicHeader[]{
	    new BasicHeader(HttpHeaders.REFERER, loginUrl)
        };
        
        String htmlDatas = httpGetDatas(url, headers);
                
        String str = htmlDatas.substring(htmlDatas.indexOf("(") + 1, htmlDatas.indexOf(");"));
        String[] strs = str.split(",");
        
        String isHasVC = strs[0].substring(strs[0].indexOf("'") + 1, strs[0].lastIndexOf("'"));
        HashMap<String,String> checkVCMap = new HashMap<String, String>();
        checkVCMap.put("isHasVC", isHasVC);        
        String vc = strs[1].substring(strs[1].indexOf("'") + 1, strs[1].lastIndexOf("'"));
        checkVCMap.put("vc", vc);        
        String saltUin = strs[2].substring(strs[2].indexOf("'") + 1, strs[2].lastIndexOf("'"));
        checkVCMap.put("saltUin", saltUin);
    
        return checkVCMap;
    }
    
    /**
     * 获取当前用户登陆所需要的验证码
     * @param username 用户名
     * @return
     */
    public String getVCode(String username) {
        
        String imageUrl = "https://ssl.captcha.qq.com/getimage?"
        + "uin=" +username
        + "&aid=46000101"
	    + "&" + Math.random();
        
        return imageUrl;
    }
    
    /**
     * 保存验证码
     * @param url 验证码链接
     */
    public void saveVCodeImg(String url) {
        
        HttpGet getImages = new HttpGet(url);
        HttpResponse response = null;
        try {
            response = httpClient.execute(getImages);
            byte[] imageBytes = EntityUtils.toByteArray(response.getEntity());                
            FileOutputStream fileWrite = new FileOutputStream("vc.jpg");
            fileWrite.write(imageBytes);
            fileWrite.close();
        } catch (ClientProtocolException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }
    
    /**
     * 模拟最终登陆
     * @param vc 验证码信息
     * @param dataRedirect 链接信息
     * @param username 用户名
     * @param password 密码
     * @param loginSig TODO
     * @param loginUrl TODO
     * @param saltUin TODO
     * @return
     */
    private String finalLogin(String vc, String saltUin, String dataRedirect, String username, 
			      String password, String loginSig, String loginUrl){
        
        String p = null;
        try {
            p = TencentWeiboEncryption.getPassword(saltUin, password, vc);
        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        String url = null;
        try {
            url = "https://ssl.ptlogin2.qq.com/login?"
		+ "u=" + URLEncoder.encode(username, "UTF-8")
                    + "&p=" + p
                    + "&verifycode=" + vc
                    + "&aid=46000101"
		+ "&u1=" + URLEncoder.encode(dataRedirect, "UTF-8")
                    + "&h=1"
                    + "&ptredirect=1"
                    + "&ptlang=2052"
                    + "&daid=6"
                    + "&from_ui=1"
                    + "&dumy="
                    + "&low_login_enable=0"
                    + "&regmaster="
                    + "&fp=loginerroralert"
		+ "&action=2-20-" + new Date().getTime()
                    + "&mibao_css="
                    + "&t=1"
                    + "&g=1"
                    + "&js_ver=10052"
                    + "&js_type=1"
                    + "&login_sig=" + loginSig
		+ "&pt_rsa=0";
        } catch (UnsupportedEncodingException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        
        Header[] headers = new BasicHeader[]{
            new BasicHeader(HttpHeaders.REFERER, loginUrl)
        };
        
        String htmlDatas = httpGetDatas(url, headers);
        String str = htmlDatas.substring(htmlDatas.indexOf("(") + 1, htmlDatas.indexOf(");"));
        String[] strs = str.split(",");
        
        String checkUrl = strs[2].substring(strs[2].indexOf("'") + 1, strs[2].lastIndexOf("'"));
        String loginResult = strs[4].substring(strs[4].indexOf("'") + 1, strs[4].lastIndexOf("'"));
        
        if (loginResult.equals("登录成功！")) {
            return checkUrl;
        }
        return loginResult;
    }
    
    
    /**
     * 获取最终授权
     * @param loginUrl
     * @param checkSigUrl
     * @return
     */
    private Properties authorize(String loginUrl, String checkSigUrl) {
        
        Properties prop = null;
        if (checkSigUrl != null) {
            Header[] headers = new BasicHeader[]{
                new BasicHeader(HttpHeaders.REFERER, loginUrl)
            };
            String htmlDatas = httpGetDatas(checkSigUrl, headers);
            
            Document  document = Jsoup.parse(htmlDatas);
            Element element = document.getElementsByTag("meta").first();
            String content = element.attr("content");;
        
            String subContent = content.substring(content.indexOf("?") + 1);
            String propStr = subContent.replace("&", "\n");
            
            prop = new Properties();
            InputStream stream = new ByteArrayInputStream(propStr.getBytes());
            try {
                prop.load(stream);
            } catch (IOException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }
        return prop;
    }
    
    
    /**
     * 提交URL,并获取页面数据(GET方式)
     * @param url 请求页面
     * @param headers http请求header
     * @return
     */
    private String httpGetDatas(String url,Header[] headers) {
        
        String response =null;
        HttpResponse httpResponse = null;
        if (url == null) {
            throw new NullPointerException("URL is null");
        }
        HttpGet httpGet = new HttpGet(url);
        httpGet.setHeaders(headers);
        
        try {
            httpResponse = httpClient.execute(httpGet);
            response = EntityUtils.toString(httpResponse.getEntity());
            
        } catch (ClientProtocolException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        return response;
    }
    
    /**
     * 初始化配置信息
     * @return
     */
    public Properties initProperties() {
        
        Properties properties = new Properties();
        InputStream inputStream = Thread.currentThread().
	    getContextClassLoader().getResourceAsStream("cfg.properties");
        try {
            properties.load(inputStream);
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        return properties;
    }
    
    public static void main(String[] args) {

        TencentWeiboLoginer loginer = new TencentWeiboLoginer();
        TLoginParams tLoginParams = loginer.doLogin("","");
	//有验证码时
        if (tLoginParams.getProp() == null) {
            String saltUin = tLoginParams.getSaltUin();
            String dataRedirect = tLoginParams.getDataRedirect();
            String loginSig = tLoginParams.getLoginSig();
            String loginUrl = tLoginParams.getLoginUrl();
            String imgUrl = tLoginParams.getImgURl();
            //要返回的验证码
            System.err.println(imgUrl);
            
            //测试再次获取验证码
            imgUrl = loginer.getVCode("");
            //保存验证码(用于测试并查看验证码)
            loginer.saveVCodeImg(imgUrl);
            
            Scanner input = new Scanner(System.in);
            String vc = input.nextLine();
            
            
            TLoginParams loginresult =loginer.doLoginByVC(vc, saltUin, dataRedirect, "", 
							  "", loginSig, loginUrl);
	    //如果验证码录入错误，则重新获取并返回验证码
            if (!loginresult.isLogin()) {
                System.err.println("验证码错误！重新录入");
                imgUrl = loginer.getVCode("");
                loginer.saveVCodeImg(imgUrl);
                Scanner input2 = new Scanner(System.in);
                String vc1 = input2.nextLine();
                Properties codeProp = loginer.doLoginByVC(vc1, saltUin, dataRedirect, "", 
							  "", loginSig, loginUrl).getProp();
                System.out.println(TencentWeiboOAuth.getOAuthV2Instance(codeProp));
            }else {
                //验证码正确则直接输出结果
                Properties codeProp = loginresult.getProp();
                System.out.println(TencentWeiboOAuth.getOAuthV2Instance(codeProp));
            }
            
        }else {
            //无验证码时
            Properties codeProp = tLoginParams.getProp();
            System.out.println(TencentWeiboOAuth.getOAuthV2Instance(codeProp));
        }
    }
}
