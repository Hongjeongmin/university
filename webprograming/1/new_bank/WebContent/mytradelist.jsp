<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import ="java.sql.*" %> 
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>잔액조회</title>
</head>
<body>
	<%
		String id = (String)session.getAttribute("id");
		
		String url = "jdbc:oracle:thin:@localhost:1521:XE"; 
		String uid = "scott";  String pass = "tiger";  
		String sql =  "select * from banktrade where id = '" + id + "' order by tradedate desc";
		try{
		Class.forName("oracle.jdbc.driver.OracleDriver");
		Connection conn = DriverManager.getConnection(url, uid, pass);
		Statement  stmt = conn.createStatement();   
		ResultSet rs = stmt.executeQuery(sql);
		String tmp="";
	%>
	
	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
	<FONT COLOR=BLUE><%= id %></FONT>님의 거래 내역은 다음과 같습니다.
	<p>
	<table border="1">
	<tr><th>거래일자(최근일순)</th><th>입금액</th><th>출금액</th><th>이체여부</<th><th>이체상대</th></tr>
	<%while (rs.next()) {%>
			<tr>
			<td><%=rs.getString("tradedate")%> </td>
			<td><%=rs.getInt("deposit")%> </td>
			<td><%=rs.getInt("withdraw")%> </td>
			<%
				tmp = rs.getInt("trans") == 0 ? "*" : rs.getInt("trans") == 1 ? "이체보냄" : "이체받음";
			%>
			<td><%= tmp %></td>
			<td><%=rs.getString("trade_id")%> </td>
			</tr>
		<%}%>
	<%} catch (Exception e){
		out.print("죄송합니다. 시스템상 문제가 생겼어요 <br>" + e.getMessage());
	}%>	
	
	</table>
	<p>
	<a href="menu.jsp" > 메뉴로 돌아가기</a>
</body>
</html>