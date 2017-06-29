package cn.cslg.Ajax;

import cn.cslg.tools.DataStruts;
import cn.cslg.tools.GetData;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Created by Administrator on 2017/5/11.
 */
public class AjaxGetDataNumber extends HttpServlet {
    public void doGet(HttpServletRequest request, HttpServletResponse response)
            throws IOException, ServletException {

        PrintWriter out = response.getWriter();
        GetData getData = new GetData();
        ArrayList<DataStruts> informations = getData.getInformations();
        out.println(informations.size());
    }

    public void doPost(HttpServletRequest request, HttpServletResponse response)
            throws IOException, ServletException {
        doGet(request,response);
    }
}