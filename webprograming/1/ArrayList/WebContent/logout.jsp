<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<% session.invalidate(); %>
<script>
alert("logout되었습니다. 메뉴로 돌아갑니다.");
location.href="menu.jsp";
</script>