<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import ="java.sql.*" %> 
<%@ page import="java.util.*,java.text.*" %>
<% 
	java.text.SimpleDateFormat formatter = new java.text.SimpleDateFormat("yyyy-MM-dd");
	String today = formatter.format(new java.util.Date());
	
	
	request.setCharacterEncoding("UTF-8"); 
	String id = (String)session.getAttribute("id");
	int deposit = Integer.parseInt(request.getParameter("deposit"));
	String url = "jdbc:oracle:thin:@localhost:1521:XE"; 
	String uid = "scott";  String pass = "tiger";  
	String sql =  "insert into banktrade values(?,?,?,?)"; 
	try{
	Class.forName("oracle.jdbc.driver.OracleDriver");
	Connection conn = DriverManager.getConnection(url, uid, pass);
	PreparedStatement pre = conn.prepareStatement(sql);
	pre.setString(1,id);
	pre.setString(2,today);
	pre.setInt(3,deposit);
	pre.setInt(4,0);
	pre.executeUpdate();
%>
<script>
alert("입금완료 되었습니다., <%=id%>님!! (메뉴 이동합니다.)");
location.href="menu.jsp";
</script>
<%} catch (Exception e) {
out.print("잘못된거 같다 ㅎㅎㅎㅎ" + e.getMessage() + "<p>");
%>
<img src="whity.png" width="300" height="200" alt="놀란 흰둥이">
<%} %> 