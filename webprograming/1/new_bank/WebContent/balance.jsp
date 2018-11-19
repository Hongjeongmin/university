<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import ="java.sql.*" %> 
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>잔액조회</title>
</head>
<body style="background-color:#E0F8F7">
	<%
		String id = (String)session.getAttribute("id");
		
		String url = "jdbc:oracle:thin:@localhost:1521:XE"; 
		String uid = "scott";  String pass = "tiger";  
		String sql = "select * from bankmember where id = '" + id + "'";
		String sql2 =  "select max(tradedate) from banktrade where id = '" + id + "'";
		try{
			Class.forName("oracle.jdbc.driver.OracleDriver");
			Connection conn = DriverManager.getConnection(url, uid, pass);
			Statement  stmt = conn.createStatement();   
			ResultSet rs = stmt.executeQuery(sql);
	%>

			<%rs = stmt.executeQuery(sql);%>
			<%rs.next();%>
			<%= id %> 님의 잔액은 <%= rs.getInt("balance") %><br>
		<%
			rs = stmt.executeQuery(sql2);
			rs.next();
		%>
			최근 거래일은 <%= rs.getString(1) %>입니다<p>
			<a href="menu.jsp" > 메뉴로 돌아가기</a>
		
		
			<%} catch (Exception e){
				out.print("죄송합니다. 시스템상 문제가 생겼어요 <br>" + e.getMessage());
			}%>	

</body>
</html>