#pragma once

namespace ts
{
    struct Point
    {
        float x,y,z;
    };

    struct Orientation
    {
        float roll, pitch, yaw;
    };

    struct IntrinsicParameters
    {
        float fu, fv, du, dv;
    };

    struct Color
    {
        uint8_t r,g,b,a;
    };

    class Camera
    {
    public:
        Camera(int width, int height, Point t, Orientation angles, IntrinsicParameters intrinsic)
        {
            m_t = t;
            m_angles = angles;
            m_intrinsic = intrinsic;
            m_width = width;
            m_height = height;
            m_picture = new Color[m_width*m_height];
            Clear();
        }
        ~Camera()
        {
            delete[] m_picture;
        }

        Color* Picture(){ return m_picture; }
        int Width(){return m_width;}
        int Height(){return m_height;}

        void dX(float dx){m_t.x += dx;}
        void dY(float dy){m_t.y += dy;}
        void dZ(float dz){m_t.z += dz;}
        void dRoll(float droll){
            m_angles.roll += droll;
        }
        void dPitch(float dpitch){m_angles.pitch += dpitch;}
        void dYaw(float dyaw){m_angles.yaw += dyaw;}
        double GetX() {return m_t.x;}
        double GetY() {return m_t.y;}
        double GetZ() {return m_t.z;}
        void Clear()
        {
            for(int i=0;i<m_height;i++)
                for(int j=0;j<m_width;j++)
                    m_picture[i*m_width+j] = {0,0,0,128};
        }

        void ProjectPoint(Point p, Color c)
        {
            float X = p.x;
            float Y = p.y;
            float Z = p.z;

            float c1 = cos(m_angles.yaw);
            float c2 = cos(m_angles.pitch);
            float c3 = cos(m_angles.roll);
            float s1 = sin(m_angles.yaw);
            float s2 = sin(m_angles.pitch);
            float s3 = sin(m_angles.roll);

            float r11 = c1*c2;
            float r12 = c1*s2*s3-s1*c3;
            float r13 = c1*s2*c3+s1*s3;
            float r21 = s1*c2;
            float r22 = s1*s2*s3+c1*c3;
            float r23 = s1*s2*c3-c1*s3;
            float r31 = -s2;
            float r32 = c2*s3;
            float r33 = c2*c3;


            float x = m_t.x + r11*X + r12*Y + r13*Z;
            float y = m_t.y + r21*X + r22*Y + r23*Z;
            float z = m_t.z + r31*X + r32*Y + r33*Z;

            // объект находится за камерой
            if(z<0)
                return;

            if(z != 0)
            {
                x = x/z;
                y = y/z;

                x = x*m_intrinsic.fu + m_intrinsic.du;
                y = y*m_intrinsic.fv + m_intrinsic.dv;

                if(x>=0 && x<m_width && y>=0 && y<m_height)
                    m_picture[(int)y*m_width+(int)x] = c;
            }
        }

    private:
        Point m_t;
        Orientation m_angles;
        IntrinsicParameters m_intrinsic;

        int m_width, m_height;
        Color* m_picture;
    };
}