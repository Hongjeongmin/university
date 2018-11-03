<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.sql.*"%>
<%
String url = "jdbc:oracle:thin:@localhost:1521:XE";
String uid = "scott"; String pass = "tiger";
String sql = "select * from member";
try{
	Class.forName("oracle.jdbc.driver.OracleDriver");
	Connection conn = DriverManager.getConnection(url,uid,pass);
	Statement stmt = conn.createStatement();
	ResultSet rs = stmt.executeQuery(sql);
%>
<table width="800" border="1">
<tr><th>이름</th><th>아이디</th><th>암호</th><th>이메일</th><th>전화번호</th><th>구분</th></tr>
<%while (rs.next()){
out.println("<tr>");
out.println("<td>" + rs.getString("name") + "</td>");
out.println("<td>" + rs.getString("userid") + "</td>");
out.println("<td>" + rs.getString("pwd") + "</td>");
out.println("<td>" + rs.getString("email") + "</td>");
out.println("<td>" + rs.getString("phone") + "</td>");
out.println("<td>" + rs.getInt("admin")+ "</td>");
out.println("</tr>");
}
%>
</table>
<%} catch (Exception e){
	out.print("죄송합니다. 시스템상 문제가 생겼어요 <br>" + e.getMessage());
}

%>
