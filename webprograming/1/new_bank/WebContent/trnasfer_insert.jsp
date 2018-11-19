<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import ="java.sql.*" %> 
<%@ page import="java.util.*,java.text.*" %>

<% 
	java.text.SimpleDateFormat formatter = new java.text.SimpleDateFormat("yyyy-MM-dd");
	String today = formatter.format(new java.util.Date());

	request.setCharacterEncoding("UTF-8"); 
	String id = (String)session.getAttribute("id");
	String you = (String)session.getAttribute("you");
	int money = Integer.parseInt((String)session.getAttribute("money"));
	
	String url = "jdbc:oracle:thin:@localhost:1521:XE"; 
	String uid = "scott";  String pass = "tiger";  
	
	//보내는 쪽의 업데이트
	String sql1 = "insert into banktrade values(?,sysdate,0,?,1,?)";
	String sql2 = "update bankmember set balance=balance-? where id=?";
	//받는 쪽의 업데이트
	String sql3 = "insert into banktrade values(?,sysdate,?,0,2,?)";
	String sql4 = "update bankmember set balance=balance+? where id=?";
	try{
	Class.forName("oracle.jdbc.driver.OracleDriver");
	Connection conn = DriverManager.getConnection(url, uid, pass);
	
	PreparedStatement pre = conn.prepareStatement(sql1); 
	pre.setString(1,id);  pre.setInt(2,money); pre.setString(3,you);
	pre.executeUpdate(); 
	
	pre = conn.prepareStatement(sql2); 
	pre.setInt(1,money); pre.setString(2,id);
	pre.executeUpdate();
	
	pre = conn.prepareStatement(sql3); 
	pre.setString(1,you);  pre.setInt(2,money); pre.setString(3,id);
	pre.executeUpdate();  
	
	pre = conn.prepareStatement(sql4); 
	pre.setInt(1,money); pre.setString(2,you);
	pre.executeUpdate();  
%>
<script>
alert("<%=money%>원이 이체 완료 되었습니다. (메뉴로 이동합니다.)");
location.href="menu.jsp";
</script>
<%} catch (Exception e) {
out.print("이체 진행 중 오류가 발생했습니다. 문의번호: 000-1111-9999 <p>" + e.getMessage());
}
%>