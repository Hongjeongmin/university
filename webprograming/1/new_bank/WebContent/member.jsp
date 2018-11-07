<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import ="java.sql.*" %> 
<% request.setCharacterEncoding("UTF-8"); String id = request.getParameter("id");
String pw = request.getParameter("pw"); String name = request.getParameter("name");
int age = Integer.parseInt(request.getParameter("age")); String phone = 
request.getParameter("phone"); 
String url = "jdbc:oracle:thin:@localhost:1521:XE"; 
String uid = "scott";  String pass = "tiger";  
String sql =  "insert into bankmember values('" + 
id + "','" + pw + "','" + name + "'," + age + ",'" + phone + "', 0)";
try{
Class.forName("oracle.jdbc.driver.OracleDriver");
Connection conn = DriverManager.getConnection(url, uid, pass);
Statement cre = conn.createStatement();   
cre.executeUpdate(sql); 
session.invalidate();  // 새로 로그인화면으로 이동하기 전에 기존 로그인 있다면 비활성화
%>
<script>
alert("환영합니다, <%=id%>님!! (로그인화면으로 이동합니다.)");
location.href="login.jsp";
</script>
<%} catch (Exception e) {
out.print("죄송합니다, 문제가 생겼어요ㅠ 문의번호: 051)200-1035 <p>" + e.getMessage() + "<p>");
%>
<img src="whity.png" width="300" height="200" alt="놀란 흰둥이">
<%} %> 