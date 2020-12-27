package net.mynoise.noiseshow.entity;

/*** 
 @author: 葛璐豪
 @学号:201741882228
 */
public class AllSensor {
    /**数据编号*/
    private int id;
    private String people;
    private String dist;
    private String light;
    private String temp;
    private String hum;

    /**ip地址*/
    private String ip;
    /**采集时间*/
    private String time;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getPeople() {
        return people;
    }

    public void setPeople(String people) {
        this.people = people;
    }

    public String getDist() {
        return dist;
    }

    public void setDist(String dist) {
        this.dist = dist;
    }

    public String getLight() {
        return light;
    }

    public void setLight(String light) {
        this.light = light;
    }

    public String getTemp() {
        return temp;
    }

    public void setTemp(String temp) {
        this.temp = temp;
    }

    public String getHum() {
        return hum;
    }

    public void setHum(String hum) {
        this.hum = hum;
    }

    public String getIp() {
        return ip;
    }

    public void setIp(String ip) {
        this.ip = ip;
    }

    public String getTime() {
        return time;
    }

    public void setTime(String time) {
        this.time = time;
    }

    @Override
    public String toString() {
        return "allSensor{" +
                "id=" + id +
                ", people='" + people + '\'' +
                ", dist='" + dist + '\'' +
                ", light='" + light + '\'' +
                ", temp='" + temp + '\'' +
                ", hum='" + hum + '\'' +
                ", ip='" + ip + '\'' +
                ", time='" + time + '\'' +
                '}';
    }
}
