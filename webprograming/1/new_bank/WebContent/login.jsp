<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import ="java.sql.*" %> 
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>login 화면</title>
</head>
<div align="center">
<body style="background-color:#F8ECE2">
<%
String url = "jdbc:oracle:thin:@localhost:1521:XE"; 
String uid = "scott";  String pass = "tiger";  
String sql =  "select * from visit";

try{
Class.forName("oracle.jdbc.driver.OracleDriver");
Connection conn = DriverManager.getConnection(url, uid, pass);
Statement cre = conn.createStatement(); 
ResultSet rs = cre.executeQuery(sql);
rs.next();

int count =(int)rs.getInt("count");


%>
로그인 횟수: <%= count %>
<p>

	<form method="post" action="check_id_3p.jsp">
		ID: <input type="text" name="id"/> <p>
		<input type="submit" value="login"/> &nbsp;&nbsp;
		<a href="member.html" > 회원가입</a><p>
	</form>
	<img src="D:\photo\image.jpg" width="300" height="360" alt="뭔가 그냥 예의상">
</body>
</div>
</html>
<%}
catch (Exception e) {
out.print("죄송합니다, 문제가 생겼어요ㅠ 문의번호: 051)200-1035 <p>" + e.getMessage());
}
%>