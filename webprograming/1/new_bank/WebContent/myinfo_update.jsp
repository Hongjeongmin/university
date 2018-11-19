<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import ="java.sql.*" %> 
<%@ page import="java.util.*,java.text.*" %>

<% 
	java.text.SimpleDateFormat formatter = new java.text.SimpleDateFormat("yyyy-MM-dd");
	String today = formatter.format(new java.util.Date());

	request.setCharacterEncoding("UTF-8"); 
	String id = (String)session.getAttribute("id");
	String url = "jdbc:oracle:thin:@localhost:1521:XE"; 
	String uid = "scott";  String pass = "tiger";  
	String sql = "update bankmember set pw = ?,name = ?, age = ?, phone =? where id = ?";
	try{
		Class.forName("oracle.jdbc.driver.OracleDriver");
		Connection conn = DriverManager.getConnection(url, uid, pass);
		PreparedStatement pre = conn.prepareStatement(sql);   
		pre.setString(1,request.getParameter("pw")); 
		pre.setString(2,request.getParameter("name")); 
		pre.setString(3,request.getParameter("age"));
		pre.setString(4,request.getParameter("phone"));
		pre.setString(5,id);
		pre.executeUpdate(); 
		%>		
	<script>
alert("변경이 완료되었습니다. (메뉴로 이동합니다.)");
location.href="menu.jsp";
</script>
<%} catch (Exception e) {
out.print("회원정보 변경중 오류가 발생했습니다. 문의번호: 000-1111-9999 <p>" + e.getMessage());
}
%>