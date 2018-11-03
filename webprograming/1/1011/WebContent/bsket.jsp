<%@page import="java.util.ArrayList"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%
	ArrayList<String> arr =(ArrayList)(session.getAttribute("arr"));
%>
<h2>장바구니 화면입니다~</h2>

<%if(arr!=null){%>
	<form method="post" action="buy.jsp">
		<%
			for(String i : arr)
			{%>
				<%=i %>
			
			<%}}%>
			
		<p><p>
		<input type="submit" value="구매하기"/> &nbsp;&nbsp;
		<a href="menu.jsp">메뉴</a>
	</form>

</body>
</html>