<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<%@ page import ="java.text.SimpleDateFormat" %>
<%@ page import ="java.util.Calendar" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>Insert title here</title>
</head>
<body>
<%
	Calendar date= Calendar.getInstance();
	SimpleDateFormat today=new SimpleDateFormat("yyyy년 MM월 dd일");
	SimpleDateFormat now=new SimpleDateFormat("hh시 mm분 ss초");
%>
오늘은 <strong> <%= today.format(date.getTime()) %></strong> 입니다. <br>
지금 시각은 <strong> <%= now.format(date.getTime()) %></strong> 입니다.

</body>
</html>