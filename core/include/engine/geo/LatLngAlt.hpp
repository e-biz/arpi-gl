/*
 * Copyright (C) 2015  eBusiness Information
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef ARPIGL_LATLNGALT_HPP
#define ARPIGL_LATLNGALT_HPP

namespace dma {

    class LatLngAlt {

    public:
        LatLngAlt(double lat, double lng, float alt)  :
                lat(lat),lng(lng), alt(alt) {}

        LatLngAlt(double lat, double lng) :
                LatLngAlt(lat, lng, 0.0f) {}

        LatLngAlt() :
                LatLngAlt(0.0, 0.0) {}

        inline bool operator==(const LatLngAlt& other) {
            return lat == other.lat
                   && lng == other.lng
                   && alt == other.alt;
        }

        double lat;
        double lng;
        float alt;
    };
}

#endif //ARPIGL_LATLNGALT_HPP
