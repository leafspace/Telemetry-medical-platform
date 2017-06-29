package cn.cslg.tools;

public class DataStruts {
    private String information;
    private String time;

    public DataStruts(String information, String time) {
        this.information = information;
        this.time = time;
    }

    public String getInformation() {
        return this.information;
    }

    public String getTime() {
        return this.time;
    }

    public void setInformation(String information) {
        this.information = information;
    }

    public void setTime(String time) {
        this.time = time;
    }
}