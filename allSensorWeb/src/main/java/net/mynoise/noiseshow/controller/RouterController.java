package net.mynoise.noiseshow.controller;
import net.mynoise.noiseshow.entity.AllSensor;
import net.mynoise.noiseshow.mapper.AllSensorMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import java.util.List;

/*** 
 @author: 葛璐豪
 @学号:201741882228
 */
@Controller
public class RouterController {
    @Autowired
    private AllSensorMapper allSensorMapper;
    @GetMapping("")
    private  String index() {
        return "index";
    }



    @GetMapping("/baseData")
    @ResponseBody
    public List<AllSensor> baseData(ModelMap modelMap)
    {
        return allSensorMapper.querrySensor();
    }
}
