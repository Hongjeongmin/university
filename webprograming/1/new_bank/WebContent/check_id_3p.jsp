<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import ="java.sql.*" %> 
<%request.setCharacterEncoding("UTF-8"); String id = request.getParameter("id");
String url = "jdbc:oracle:thin:@localhost:1521:XE"; 
String uid = "scott";  String pass = "tiger";  
String sql =  "select * from bankmember where id = ?";
String sql2 =  "update visit set count = count + 1";
try{
Class.forName("oracle.jdbc.driver.OracleDriver");
Connection conn = DriverManager.getConnection(url, uid, pass);
PreparedStatement pre = conn.prepareStatement(sql);
pre.setString(1,id);
pre.executeUpdate(); 
ResultSet rs = pre.executeQuery();

if(rs.next()) {
session.setAttribute("id", id);
session.setMaxInactiveInterval(60*60);  // 테스트 편의 위해 1시간
pre = conn.prepareStatement(sql2);

ResultSet rs2 = pre.executeQuery();
response.sendRedirect("menu.jsp");
}
%>
<script>
alert("미등록 아이디입니다~  문의전화: 051)200-1035");
location.href="login.jsp";
</script>
<%} catch (Exception e) {
out.print("죄송합니다, 문제가 생겼어요ㅠ 문의번호: 051)200-1035 <p>" + e.getMessage());
}
%>