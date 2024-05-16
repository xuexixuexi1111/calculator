from ctypes import *
import tkinter as tk
pi = 3.141592627

class TrigonometricCalculatorLogic:
    def __init__(self):
        self.dll = cdll.LoadLibrary(r'./tri_cul.dll')
        # 指定函数的返回类型为 double
        self.dll.sin_taylor.restype = c_double
        self.dll.cos_taylor.restype = c_double
        self.dll.tan_taylor.restype = c_double
        self.dll.arctan.restype = c_double
        self.dll.arcsin.restype = c_double
        self.dll.arccos.restype = c_double

    # 角度转弧度
    def input_angle(self, x):
        while x >= 360.0:
            x -= 360.0
        return x * pi / 180.0

    def calculate_trig(self, func, angle,unit):
        try:
            angle = float(angle)

            if func == "arcsin":
                result = self.dll.arcsin(c_double(angle))
            elif func == "arccos":
                result = self.dll.arccos(c_double(angle))
            elif func == "arctan":
                result = self.dll.arctan(c_double(angle))


            if unit == 'deg':
                angle = self.input_angle(angle)
            angle = c_double(angle)
            if func == "sin":
                result = self.dll.sin_taylor(angle,10)
            elif func == "cos":
                result = self.dll.cos_taylor(angle,10)
            elif func == "tan":
                result = self.dll.tan_taylor(angle,10)

            return str(result)
        except ValueError:
            return "请输入有效数字"
        ######v2.0新增输入检测#########
        except ZeroDivisionError:
            return "无效的角度"


class TrigonometricCalculatorUI:
    def __init__(self, root):
        self.root = root
        self.root.title("三角函数计算器")
        self.root.configure(bg="#f0f0f0")

        self.logic = TrigonometricCalculatorLogic()

        # 创建单位选择单选框和标签
        self.unit_label = tk.Label(self.root, text="单位", bg="#f0f0f0")
        self.unit_label.grid(row=0, column=0, padx=10, pady=10, sticky=tk.W)

        self.unit_var = tk.StringVar()
        self.unit_var.set("角度制")  # 默认选择角度制
        self.deg_rad_radiobutton = tk.Radiobutton(self.root, text="弧度制", variable=self.unit_var, value="rad")
        self.deg_rad_radiobutton.grid(row=0, column=1, padx=5, pady=5, sticky=tk.W)

        self.rad_deg_radiobutton = tk.Radiobutton(self.root, text="角度制", variable=self.unit_var, value="deg")
        self.rad_deg_radiobutton.grid(row=0, column=2, padx=5, pady=5, sticky=tk.W)

        # 创建角度输入框和标签
        self.angle_label = tk.Label(self.root, text="输入数值", bg="#f0f0f0")
        self.angle_label.grid(row=1, column=0, padx=10, pady=10, sticky=tk.W)

        self.angle_entry = tk.Entry(self.root, width=20)
        self.angle_entry.grid(row=1, column=1, padx=10, pady=10)

        # 创建清除按钮
        self.clear_button = tk.Button(self.root, text="清除", command=self.clear, bg="#d9534f", fg="white", width=10)
        self.clear_button.grid(row=1, column=2, padx=10, pady=10, sticky=tk.W)

        # 创建三角函数计算按钮
        self.create_trig_buttons()

        # 创建结果显示框和标签
        self.result_label = tk.Label(self.root, text="结果", bg="#f0f0f0")
        self.result_label.grid(row=2, column=0, padx=10, pady=10, sticky=tk.W)

        self.result_entry = tk.Entry(self.root, width=20)
        self.result_entry.grid(row=2, column=1, padx=10, pady=10)



    def create_trig_buttons(self):
        trig_funcs = ["sin", "cos", "tan", "arcsin", "arccos", "arctan"]

        for idx, func in enumerate(trig_funcs):
            button = tk.Button(self.root, text=func, command=lambda f=func: self.trig_button_clicked(f), bg="#00994C",
                               fg="white", width=8)
            button.grid(row=3 + idx // 3, column=idx % 3, padx=5, pady=5, sticky=tk.EW)

    def clear(self):
        self.angle_entry.delete(0, tk.END)
        self.result_entry.delete(0, tk.END)

    def trig_button_clicked(self, func):
        angle = self.angle_entry.get()
        #####获取单位######
        unit = self.unit_var.get()
        result = self.logic.calculate_trig(func, angle,unit)
        self.result_entry.delete(0, tk.END)
        self.result_entry.insert(0, result)






if __name__ == "__main__":
    root = tk.Tk()
    app = TrigonometricCalculatorUI(root)
    root.mainloop()
