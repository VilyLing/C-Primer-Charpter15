#ifndef GEOMETRIC_HPP
#define GEOMETRIC_HPP
    class Geometric{
        public:
            Geometric(double w, double h):_w(w),_h(h){}
        protected:
            double _w;
            double _h;
    };

    class Geometric2D:public Geometric{
        public:
            Geometric2D(double w, double h):Geometric(w, h){};
            virtual double aera() = 0;
    };

    class Geometric3D:public Geometric{
        public:
            Geometric3D(double w, double h, double l):Geometric(w, h),_length(l){}
            virtual double volume() = 0;
        protected:
            double _length;
    };

    class Rectangle :public Geometric2D{
        public:
            Rectangle(double w, double h):Geometric2D(w, h){}
            double aera() override{
                return _w * _h;
            }
    };

    class Circle : public Geometric2D{
        public:
            Circle(double w,double h):Geometric2D(w,h){}
            double aera() override{
                return _h*PI;
            }
        private:
            inline static double PI = 3.14; 
    };

    class Sphere : public Geometric3D{
        public:
            Sphere(double w, double h,double l):Geometric3D(w, h, l){}
            double volume() override{
                return (4/3)*PI * _w * _h*_length;
            }
        private:
        inline static double PI = 3.14;
    };

    class Cone: public Geometric3D{
        public:
            Cone(double w, double h, double l):Geometric3D(w, h, l){}
            double volume() override{
                return (1/3)*PI*_h*_w*_length;
            }
        private:
            inline static double PI = 3.14;
    };
#endif