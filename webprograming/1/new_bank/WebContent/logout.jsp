<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>Insert title here</title>
</head>
<body>
<%
	String id = (String)session.getAttribute("id");
	session.invalidate();
%>
<h2>�α׾ƿ��ϼ˽��ϴ�. <FONT COLOR=BLUE><%= id %></FONT>��, �� �湮�� �ּ���!</h2>

ù ȭ������ ���÷��� �Ʒ� �׸��� Ŭ���� �ּ���~<br>
<a href="login.jsp"><img src="D:\photo\image.jpg" width="300" height="360" alt="���� �׳� ���ǻ�"></a>
</body>
</html>