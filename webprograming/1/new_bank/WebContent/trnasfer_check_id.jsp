<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import ="java.sql.*" %> 
<%request.setCharacterEncoding("UTF-8");
String you = request.getParameter("you");
String url = "jdbc:oracle:thin:@localhost:1521:XE"; 
String uid = "scott";  String pass = "tiger";  
String sql =  "select * from bankmember where id = '" + you + "'";
String money = request.getParameter("money");
try{
Class.forName("oracle.jdbc.driver.OracleDriver");
Connection conn = DriverManager.getConnection(url, uid, pass);
Statement cre = conn.createStatement(); 
ResultSet rs = cre.executeQuery(sql);
if(rs.next()) {
	session.setAttribute("you",you);
	session.setAttribute("money",money);
	response.sendRedirect("trnasfer_insert.jsp");
}
%>
<script>
alert("이체할 대상이 존재하지않습니다 이전 화면으로 돌아갑니다.");
location.href="trnasfer.jsp";
</script>
<%} catch (Exception e) {
out.print("죄송합니다, 문제가 생겼어요ㅠ 문의번호: 051)200-1035 <p>" + e.getMessage());
}
%>