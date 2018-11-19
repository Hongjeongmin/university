<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import ="java.sql.*" %> 
<%@ page import="java.util.*,java.text.*" %>

<%
request.setCharacterEncoding("UTF-8"); 

String url = "jdbc:oracle:thin:@localhost:1521:XE"; 
String uid = "scott";  String pass = "tiger"; 
String sql = "update idol set pyo = pyo + 1 where star = ?";
try{
	Class.forName("oracle.jdbc.driver.OracleDriver");
	Connection conn = DriverManager.getConnection(url, uid, pass);
	PreparedStatement pre = conn.prepareStatement(sql);   
	pre.setString(1,request.getParameter("star")); 

	pre.executeUpdate(); 
	%>		
<script>
alert("투표 완료");
location.href="vote.jsp";
</script>
<%} catch (Exception e) {
out.print("투표중 오류가 발생했습니다." + e.getMessage());
}
%>
