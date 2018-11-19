<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import ="java.sql.*" %> 
<%request.setCharacterEncoding("UTF-8"); 
String id = (String)session.getAttribute("id");
String pw = request.getParameter("pw");
String url = "jdbc:oracle:thin:@localhost:1521:XE"; 
String uid = "scott";  String pass = "tiger";  
String sql =  "select pw from bankmember where id = ?";
try{
Class.forName("oracle.jdbc.driver.OracleDriver");
Connection conn = DriverManager.getConnection(url, uid, pass);
PreparedStatement pre = conn.prepareStatement(sql);
pre.setString(1,id);
pre.executeUpdate(); 
ResultSet rs = pre.executeQuery();

if(rs.next()) {
	if(rs.getString("pw").equals(pw))
	{response.sendRedirect("myinfo.jsp");}
}
%>
<script>
alert("비밀번호가 틀렸습니다.");
location.href="check_pw.jsp";
</script>
<%} catch (Exception e) {
out.print("죄송합니다, 문제가 생겼어요ㅠ 문의번호: 051)200-1035 <p>" + e.getMessage());
}
%>