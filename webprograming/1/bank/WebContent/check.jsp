<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<!-- check.jsp -->
<html>
<head>
<meta charset="UTF-8">
<title>잔액조회화면이에요~</title>
</head>
<%
	Integer money = (Integer)session.getAttribute("money");
	Integer input_cnt = (Integer)session.getAttribute("input_cnt");
	Integer output_cnt = (Integer)session.getAttribute("output_cnt");
%>
<body>
<h2>고객님의 잔액</h2>
고객님의 잔액은 현재  잔액:<strong><%= money %></strong><p>
입금 횟수:<strong><%= input_cnt %></strong><p>
출금 횟수:<strong><%= output_cnt %></strong><p>
<form method="post" action="menu.jsp">
	<input type="submit" value="되돌아가기"/>
</form>
</body>
</html>