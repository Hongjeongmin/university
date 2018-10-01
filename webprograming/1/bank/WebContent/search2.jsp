<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<!-- search2.jsp -->
<html>
<head>
<meta charset="UTF-8">
</head>
<body>
<%
Integer money = (Integer)session.getAttribute("money");
String i = request.getParameter("money");
int money_input = Integer.parseInt(i);

money= money+money_input;
session.setAttribute("money",money);
session.setMaxInactiveInterval(60*60);

Integer input_cnt = (Integer)session.getAttribute("input_cnt");
input_cnt++;
session.setAttribute("input_cnt",input_cnt);
session.setMaxInactiveInterval(60*60);

%>

<script>

alert("입금완료!");
location.href="menu.jsp";

</script>
</body>
</html>