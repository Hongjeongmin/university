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
	SimpleDateFormat today=new SimpleDateFormat("yyyy�� MM�� dd��");
	SimpleDateFormat now=new SimpleDateFormat("hh�� mm�� ss��");
%>
������ <strong> <%= today.format(date.getTime()) %></strong> �Դϴ�. <br>
���� �ð��� <strong> <%= now.format(date.getTime()) %></strong> �Դϴ�.

</body>
</html>