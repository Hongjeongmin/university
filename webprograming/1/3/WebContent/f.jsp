<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>Insert title here</title>
</head>
<body>
<%! 
String dd = "�ٶ���";
public String getMethod(){return dd;}	
%>
<%
String ss = "�Ŀ���"; String cc = "����";
/* �ϴ��� �Ķ��׿�~*/
out.print("dd");
%>
�ٴٵ� �Ķ��׿� ~<br>��~
<%= ss + cc %><br>
/* ���� �Ķ��ŵ� */
*/ �ó�����? /*
<%=getMethod() %><br>
//
<!-- �� ��׸�~ -->
<%-- �ʵ� ��׸�~ --%>

�����
</body>
</html>