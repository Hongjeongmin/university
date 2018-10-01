<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<!-- search.jsp -->
<html>
<head>
<meta charset="UTF-8">
</head>
<%
Integer money = (Integer)session.getAttribute("money");
String i = request.getParameter("money");
int money_output = Integer.parseInt(i);

if(money-money_output<0)
{
%>
<script>
	alert("잔액보다 많은 출금을 요구하셨습니다. 화면으로 돌아갑니다.");
	location.href="output.jsp";
</script>
<% 	
}
else
{
	money = money-money_output;
	session.setAttribute("money",money);
	session.setMaxInactiveInterval(60*60);
	Integer output_cnt = (Integer)session.getAttribute("output_cnt");
	output_cnt++;
	session.setAttribute("output_cnt",output_cnt);
	session.setMaxInactiveInterval(60*60);	
%>
<script>
	alert("출금완료!");
	location.href="menu.jsp";
</script>
<% 
}
%>
<body>

</body>
</html>