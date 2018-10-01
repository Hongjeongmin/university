<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
<%
	request.setCharacterEncoding("UTF-8");
	String yourname = request.getParameter("name");
	String yourcolor = request.getParameter("color");
%>


</head>


<body style="background-color:<%=yourcolor%>">

	<strong> <%= yourname %></strong>님이 좋아하는 색깔은 <br>
	<strong> <%= yourcolor %></strong> 입니다
</body >
<% response.sendRedirect("http://www.donga.ac.kr"); %>

</html>