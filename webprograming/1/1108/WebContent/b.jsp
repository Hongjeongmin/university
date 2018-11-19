<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import ="java.sql.*" %> 
<%request.setCharacterEncoding("UTF-8"); String id = request.getParameter("id");
String url = "jdbc:oracle:thin:@localhost:1521:XE"; 
String uid = "scott";  String pass = "tiger";  
String sql =  "select * from idol where name = ?";
try{
Class.forName("oracle.jdbc.driver.OracleDriver");
Connection conn = DriverManager.getConnection(url, uid, pass);
PreparedStatement pre = conn.prepareStatement(sql);
pre.setString(1,id);
pre.executeUpdate(); 
ResultSet rs = pre.executeQuery();

if(rs.next()) {
	
	out.println("투표: " + rs.getInt("pyo"));
	%><a href="a.jsp" > 돌아가기</a><p><% 
}
else{%>
<script>
alert("없는 가수입니다");
location.href="a.jsp";
</script>
<%}} catch (Exception e) {
out.print("죄송합니다, 문제가 생겼어요ㅠ 문의번호: 051)200-1035 <p>" + e.getMessage());
}
%>