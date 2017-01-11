class Vector2D
{
    protected:
        float m_x;
        float m_y;
    public:
        Vector2D(float x = 0.0, float y = 0.0)
        {
            m_x = x;
            m_y = y;
        }
        ~Vector2D(){}
        void setPoint(float x = 0.0, float y = 0.0)
        {
            m_x = x;
            m_y = y;
        }
        float x()
        {
            return m_x;
        }
        float y()
        {
            return m_y;
        }
        void setX(float x)
        {
            m_x = x;
        }
        void setY(float y)
        {
            m_y = y;
        }
        void Truncate(float upperBound)
        {
            float sqrLen = length();
            if(sqrLen > upperBound * upperBound)
            {
                float mult = upperBound/sqrt(sqrLen);
                m_x *= mult; m_y *= mult;
            }
        }
        float length() const
        {
            return sqrt((m_x * m_x) + (m_y * m_y));
        }
        float lengthSquared() const
        {
            return m_x * m_x + m_y * m_y;
        }
        float distance(const Point &p)
        {
            return sqrt((m_x - p.m_x) * (m_x - p.m_x) + (m_y - p.m_y) * (m_y - p.m_y));
        }
        float distanceSquared(const Point &p)
        {
            return (m_x - p.m_x) * (m_x - p.m_x) + (m_y - p.m_y) * (m_y - p.m_y);
        }
        float dot(const Point &p)
        {
            return m_x * p.m_x + m_y * p.m_y;
        }
        float cross(const Point &p)
        {
            return m_x * p.m_y - m_y * p.m_x;
        }
        Point& ortho()
        {
            setPoint(-m_y, m_x);
            return *this;
        }
        float normal(float desiredNorm = 1.f)
        {
            float len = length();
            if(len > EPSILON){
                float mult = desiredNorm/len; 
                m_x *= mult; m_y *= mult;
                return len;
            }
            m_x = m_y = 0.f;
            return 0.f;
        }
        Point& normalize()
        {
            if(length() != 0){
                float len = length();
                m_x /= len;
                m_y /= len;
                return *this;
            }
            m_x = m_y = 0;
            return *this;
        }
        Point& setAdd(Point& p)
        {
            m_x = m_x + p.x();
            m_y = m_y + p.y();
            return *this;
        }
        Point& setSub(Point& p)
        {
            m_x = m_x - p.x();
            m_y = m_y - p.y();
            return *this;
        }
        Point& scaleBy(float nb = 1.f)
        {
            m_x *= nb;
            m_y *= nb;
            return *this;
        }
};